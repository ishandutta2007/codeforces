#include <bits/stdc++.h>

using namespace std;

typedef double ftype;

struct matrix
{
	ftype m[3][3];
	
	matrix(bool identity = true)
	{
		memset(m, 0, sizeof(m));
		
		if (identity)
		{
			m[0][0] = m[1][1] = m[2][2] = 1;
		}
	}
	
	matrix operator*(const matrix& o)
	{
		matrix r(false);
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					r.m[i][j] += m[i][k] * o.m[k][j];
				
		return r;
	}
	
	void print()
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
				printf("%.2Lf ", m[y][x]);
			printf("\n");
		}
		printf("---\n");
	}
};

matrix theMatrix;
bool leftMul;

struct segtree
{
	int n;
	vector<matrix> tree;
	
	segtree(int n): n(n), tree(n * 4 + 100)
	{}
	
	void change(int index, matrix mat, bool left)
	{
		theMatrix = mat;
		leftMul = left;
		change(0, 0, n - 1, index);
	}
	
	void change(int t, int l, int r, int index)
	{
		if (l == r)
		{
			if (leftMul)
				tree[t] = theMatrix * tree[t];
			else
				tree[t] = tree[t] * theMatrix;
			
			return;
		}
		
		int m = (l + r) / 2;
		
		if (index <= m)
			change(t * 2 + 1, l, m, index);
		else
			change(t * 2 + 2, m + 1, r, index);
		
		tree[t] = tree[t * 2 + 1] * tree[t * 2 + 2];
	}
	
	pair<ftype, ftype> getFinalVec(ftype x, ftype y)
	{
		matrix m = tree[0];
		return make_pair(m.m[0][0] * x + m.m[0][1] * y, m.m[1][0] * x + m.m[1][1] * y);
	}
	
	void printFinalVec()
	{
		matrix m = tree[0];
		printf("%.10f %.10f\n", (double)m.m[0][2], (double)m.m[1][2]);
		
		//m.print();
	}
};

matrix getTranslate(ftype x, ftype y)
{
	matrix tr;
	tr.m[0][2] = x;
	tr.m[1][2] = y;
	return tr;
}

matrix getRotate(ftype alpha)
{
	matrix tr;
	tr.m[0][0] = cos(alpha);
	tr.m[0][1] = -sin(alpha);
	tr.m[1][0] = sin(alpha);
	tr.m[1][1] = cos(alpha);
	return tr;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	segtree ops(n);
	
	for (int i = 0; i < n; i++)
		ops.change(i, getTranslate(1, 0), true);
	
	//(getTranslate(1, 0) * getTranslate(1, 0)).print();
	
	//ops.printFinalVec();
	
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		y--;
		
		if (x == 1)
		{
			matrix m = getTranslate(z, 0);
			ops.change(y, m, false);
		}
		else
		{
			const long double pi = acosl(-1);
			matrix m = getRotate(-z / 180.0 * pi);
			ops.change(y, m, true);
		}
		
		ops.printFinalVec();
	}
	
	return 0;
}