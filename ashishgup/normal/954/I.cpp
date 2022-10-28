#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef complex<double> base;

const double PI = acos(-1.0l);
const int N = 125005;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=13313;

vector<int> rev;
vector<base> omega;

void calc_rev(int n, int log_n) //Call this before FFT
{
	omega.assign(n, 0);
	rev.assign(n, 0);
	for(int i=0;i<n;i++)
	{
		rev[i]=0;
		for(int j=0;j<log_n;j++)
		{
			if((i>>j)&1)
				rev[i] |= 1<<(log_n-j-1);
		}
	}
}

void fft(vector<base> &A, int n, bool invert)
{
	for(int i=0;i<n;i++)
	{
		if(i<rev[i])
			swap(A[i], A[rev[i]]);
	}
	for(int len=2;len<=n;len<<=1)
	{
		double ang=2*PI/len * (invert?-1:+1);
		int half=(len>>1);

		base curomega(cos(ang), sin(ang));
		omega[0]=base(1, 0);

		for(int i=1;i<half;i++)
			omega[i]=omega[i-1]*curomega;

		for(int i=0;i<n;i+=len)
		{
			base t;
			int pu = i,
				pv = i+half,
				pu_end = i+half,
				pw = 0;
			for(; pu!=pu_end; pu++, pv++, pw++)
			{
				t=A[pv] * omega[pw];
				A[pv] = A[pu] - t;
				A[pu] += t;
			}
		}
	}

	if(invert)
		for(int i=0;i<n;i++)
			A[i]/=n;
}

void multiply(int n, vector<base> &A, vector<base> &B, vector<int> &C)
{
	fft(A, n, false);
	fft(B, n, false);
	for(int i=0;i<n;i++)
		A[i] *= B[i];
	fft(A, n, true);
	for(int i=0;i<n;i++)
	{
		C[i] = (int)(A[i].real() + 0.5);
	}
}

void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result)
{
	vector<base> A(n), B(n);
	for(int i=0;i<n;i++)
	{
		A[i]=coeffA[i];
		B[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		B[i]=coeffB[i];
	}
	vector<int> C(n);
	multiply(n, A, B, C);
	for(int i=0;i<n;i++)
	{
		int add=C[i];
		result[i]+=add;
	}
}

void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result)
{
	int n=1, bits=0;
	while(n<2*A.size() || n<2*B.size())
		n<<=1, bits++;
	result.assign(n, 0);
	calc_rev(n, bits);
	vector<int> tempA(A.begin(), A.end());
	vector<int> tempB(B.begin(), B.end());
	tempA.resize(n);
	tempB.resize(n);
	Solve(n, tempA, tempB, result);
}

int n, m;
string a, b;
vector<int> idx[6][2];
vector<int> g[N][6];
int vis[6];

int dfs(int u, int v)
{
	int ans=1;
	vis[v]=1;
	for(auto k:g[u][v])
	{
		if(!vis[k])
			ans+=dfs(u, k);
	}
	return ans;
}

int work(int pos)
{
	int ans=0;
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<6;i++)
	{
		if(!vis[i])
			ans+=dfs(pos, i) - 1;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size();
	m=b.size();
	for(int i=0;i<n;i++)
		idx[a[i]-'a'][0].push_back(i);
	for(int i=0;i<m;i++)
		idx[b[i]-'a'][1].push_back(i);
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(i==j)
				continue;
			vector<int> poly1(n+1, 0), poly2(m, 0);
			for(int x:idx[i][0])
				poly1[x]=1;
			for(int x:idx[j][1])
				poly2[m-1-x]=1;
			vector<int> res;
			do_FFT(poly1, poly2, res);
			for(int k=0;k<n-m+1;k++)
			{
				if(res[m-1+k])
				{
					g[k][i].push_back(j);
					g[k][j].push_back(i);
				}
			}
		}
	}
	for(int i=0;i<n-m+1;i++)
		cout<<work(i)<<" ";
	return 0;
}