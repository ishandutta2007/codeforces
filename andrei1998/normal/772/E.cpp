#include <bits/stdc++.h>

//20:13
using namespace std;

const int NMAX = 1000 + 5;

int N, sz;
int leftSon[2 * NMAX];
int rightSon[2 * NMAX];
int father[2 * NMAX];
pair <int, int> queryPair[2 * NMAX];

string askDir(int node, int searched) {
    cout << queryPair[node].first << ' ' << queryPair[node].second << ' ' << searched << endl;
    char ans;
    cin >> ans;
    if (ans == 'X')
        return "UP";
    else if (ans == 'Z')
        return "LEFT";
    else
        return "RIGHT";
}

bool vis[2 * NMAX];
int szs[2 * NMAX];

void computeSzs(int node, int f) {
    szs[node] = 1;
    for (auto it: {leftSon[node], rightSon[node], father[node]})
        if (it && it != f && !vis[it]) {
            computeSzs(it, node);
            szs[node] += szs[it];
        }
}

int getCentroid(int node, int f, int atMost) {
    for (auto it: {leftSon[node], rightSon[node], father[node]})
        if (it && it != f && !vis[it] && szs[it] > atMost)
            return getCentroid(it, node, atMost);
    //Centoid may not be a leaf
    if (node <= N) {
        for (auto it: {leftSon[node], rightSon[node], father[node]})
            if (it && it != f && !vis[it])
                return getCentroid(it, node, atMost);
        return -1;
    }
    else
        return node;
}

void insertOnEdge(int node, int searched) {
    if (father[node] == 0) {
        ++ sz;
        leftSon[sz] = node;
        father[node] = sz;
        rightSon[sz] = searched;
        queryPair[sz] = {queryPair[node].first, searched};
        father[searched] = sz;
    }
    else if (node == leftSon[father[node]]) {
        node = father[node];
        ++ sz;

        leftSon[sz] = leftSon[node];
        father[leftSon[node]] = sz;
        leftSon[node] = sz;
        father[sz] = node;
        rightSon[sz] = searched;

        queryPair[sz] = {queryPair[leftSon[sz]].first, searched};
        father[searched] = sz;
    }
    else {
        node = father[node];
        ++ sz;

        rightSon[sz] = rightSon[node];
        father[rightSon[node]] = sz;
        rightSon[node] = sz;
        father[sz] = node;
        leftSon[sz] = searched;

        queryPair[sz] = {searched, queryPair[rightSon[sz]].second};
        father[searched] = sz;
    }
}

void findAndUpdate(int node, int searched) {
    computeSzs(node, 0);
    int cent = getCentroid(node, 0, szs[node] / 2);

    if (cent == -1) {
        insertOnEdge(node, searched);
        return ;
    }

    node = cent;
    vis[node] = true;

    string ask = askDir(node, searched);
    if (ask == "UP") {
        if (!vis[father[node]] && father[node])
            findAndUpdate(father[node], searched);
        else
            insertOnEdge(node, searched);
    }
    else if (ask == "LEFT") {
        if (!vis[leftSon[node]])
            findAndUpdate(leftSon[node], searched);
        else
            insertOnEdge(leftSon[node], searched);
    }
    else {
        if (!vis[rightSon[node]])
            findAndUpdate(rightSon[node], searched);
        else
            insertOnEdge(rightSon[node], searched);
    }
}

int main()
{
    cin >> N;

    sz = N + 1;

    leftSon[sz] = 1;
    rightSon[sz] = 2;
    father[1] = father[2] = sz;
    queryPair[sz] = {1, 2};
    for (int i = 1; i <= N; ++ i)
        queryPair[i] = {i, i};

    for (int i = 3; i <= N; ++ i) {
        memset(vis, 0, sizeof vis);
        findAndUpdate(sz, i);
    }

    cout << "-1" << endl;
    for (int i = 1; i <= sz; ++ i)
        if (father[i] == 0)
            father[i] = -1;
    for (int i = 1; i <= sz; ++ i)
        cout << father[i] << " \n"[i == sz];
    cout.flush();
    return 0;
}