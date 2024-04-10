#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

const double PI = acos(-1);

struct point {
    point () : x(0), y(0) {};
    point (double x, double y) : x(x), y(y) {};
    double x;
    double y;
};

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator * (point a, double c) {
    return point(a.x * c, a.y * c);
}

double len(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

struct matrix {
    matrix() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                a[i][j] = (int)(i == j);
    }
    double a[3][3];
};

matrix rotation(double alpha) {
    matrix ans;
    ans.a[0][0] = cos(alpha);
    ans.a[0][1] = sin(alpha);
    ans.a[1][0] = -sin(alpha);
    ans.a[1][1] = cos(alpha);
    return ans;
}

matrix shift(point p) {
    matrix ans;
    ans.a[0][2] = p.x;
    ans.a[1][2] = p.y;
    return ans;
}

struct node {
    node() {};
    node(matrix m) : m(m) {};
    int l, r;
    node *left, *right;
    matrix m;
};

matrix operator * (matrix m1, matrix m2) {
    matrix ans;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            ans.a[i][j] = 0;
            for (int k = 0; k < 3; k++)
                ans.a[i][j] += m1.a[i][k] * m2.a[k][j];
        }
    return ans;
}

node *buildTree(int l, int r) {
    node *a = new node;
    a->l = l;
    a->r = r;
    if (r - l == 1) {
        a->m = shift(point(r, 0));
        return a;
    }
    a->left = buildTree(l, (l + r) / 2);
    a->right = buildTree((l + r) / 2, r);
    return a;
}

void push(node *a) {
    a->left->m = a->m * a->left->m;
    a->right->m = a->m * a->right->m;
    a->m = matrix();
}

void update(node *a, int l, int r, matrix m) {
    if (a->l == l && a->r == r) {
        a->m = m * a->m;
        return;
    }
    push(a);
    int mid = (a->l + a->r) / 2;
    if (r <= mid)
        update(a->left, l, r, m);
    if (mid <= l)
        update(a->right, l, r, m);
    if (l < mid && mid < r) {
        update(a->left, l, mid, m);
        update(a->right, mid, r, m);
    }
}

matrix getTr(node *a, int p) {
    if (p < a->l || a->r <= p)
        return matrix();
    if (a->r - a->l <= 1)
        return a->m;
    push(a);
    int mid = (a->l + a->r) / 2;
    if (p < mid)
        return getTr(a->left, p);
    else
        return getTr(a->right, p);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    scanf("%d %d", &n, &m);
    node *tree = buildTree(0, n);
    for (int i = 0; i < m; i++) {
        int x, y;
        double z;
        cin >> x >> y >> z;
        y--;
        if (x == 1) {
            matrix p = getTr(tree, y - 1);
            matrix q = getTr(tree, y);
            point v(q.a[0][2] - p.a[0][2], q.a[1][2] - p.a[1][2]);
            v = v * (z / len(v));
            update(tree, y, n, shift(v));
        }
        else {
            matrix p = getTr(tree, y - 1);
            point v(p.a[0][2], p.a[1][2]);
            matrix t = shift(v) * rotation(z / 180 * PI) * shift(point() - v);
            update(tree, y, n, t);
        }
        matrix ans = getTr(tree, n - 1);
        printf("%.9lf %.9lf\n", ans.a[0][2], ans.a[1][2]);
    }
    return 0;
}