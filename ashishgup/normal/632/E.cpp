#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
typedef complex<double> base;
 
const double PI = acos(-1.0l);
const int N = 1005;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=13313;
 
vector<int> rev;
vector<base> omega;
 
void calc_rev(int n, int log_n) //Call this before FFT
{
	rev.resize(n);
	omega.resize(n);
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
			int 	pu = i,
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
		C[i] = min(C[i], 1LL);
	}
}
 
void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result)
{
	vector<base> A(n), B(n);
	for(int i=0;i<n;i++)
		A[i]=coeffA[i];
	for(int i=0;i<n;i++)
		B[i]=coeffB[i];
	multiply(n, A, B, result);
}
 
void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result)
{
	int n=1, bits=0;
	while(n<2*A.size() || n<2*B.size())
		n<<=1, bits++;
	result.resize(n, 0);
	calc_rev(n, bits);
	vector<int> tempA(A.begin(), A.end());
	vector<int> tempB(B.begin(), B.end());
	tempA.resize(n);
	tempB.resize(n);
	Solve(n, tempA, tempB, result);
}
 
int k, q, curlen, idx=0;
int a[N], f[N];
vector<int> poly(1001, 0);

vector<int> poly_expo(vector<int> &p, int n)
{
	vector<int> res=p;
	n--;
	while(n>0)
	{
		if(n%2)
		{
			vector<int> temp;
			do_FFT(res, p, temp);
			res=temp;
		}
		vector<int> temp;
		do_FFT(p, p, temp);
		p=temp;
		n/=2;
	}
	return res;
}

int n;
 
int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=1;i<=1000;i++)
	{
		if(f[i])
		{
			poly[i]=1;
		}
	}
	vector<int> ans = poly_expo(poly, k);
	for(int i=0;i<ans.size();i++)
		if(ans[i]>0 && i>0)
			cout<<i<<" ";
	return 0;
}