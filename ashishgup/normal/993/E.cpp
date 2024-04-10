#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

typedef complex<double> base;

const double PI = acos(-1.0l);
const int N = 8e5+5;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=13313;

double error=0;

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
		error = max(error, abs(A[i].real() - (int)(A[i].real() + 0.5)));
	}
}

void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result, bool big1, bool big2) //Call 4 times: 00, 01, 10, 11
{
	vector<base> A(n), B(n);
	for(int i=0;i<n;i++)
	{
		A[i]=big1?coeffA[i]/Maxp : coeffA[i]%Maxp;
		B[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		B[i]=big2?coeffB[i]/Maxp : coeffB[i]%Maxp;
	}
	vector<int> C(n);
	multiply(n, A, B, C);
	for(int i=0;i<n;i++)
	{
		int add=C[i];
		if(big1)
			add*=Maxp;
		if(big2)
			add*=Maxp;
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
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			Solve(n, tempA, tempB, result, i, j);
		}
	}
}

int n, x;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n>>x;
	vector<int> poly1(n+1, 0), poly2(n+1, 0);
	poly1[0]++;
	poly2[n]++;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + (a[i]<x);
		poly1[pref[i]]++;
		poly2[n-pref[i]]++;
	}
	vector<int> ans;
	do_FFT(poly1, poly2, ans);
	assert(error<1e-3);
	int zero=0;
	for(auto it:poly1)
		zero+=(it*(it-1))/2;
	cout<<zero<<" ";
	for(int i=1;i<=n;i++)
		cout<<ans[n+i]<<" ";
	return 0;
}