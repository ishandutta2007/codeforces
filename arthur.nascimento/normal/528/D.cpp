#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pim pair<int,multiset<int> >
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 998244353
#define maxn 524524

using namespace std;

const int g = 3;

long long pr[maxn];
long long prI[maxn];
int v[maxn];
int tmp[maxn];

int P[maxn];

long long exp(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long k = exp(a,b/2);
    k = (k*k)%mod;
    if(b%2) k = (k*a) % mod;
    return k;
}

int n2;
void dft(int n,int poly,int jump,int write){
    
    if(n == 1){
        v[write] = P[poly];
        return;
    }
    
    dft(n/2,poly,2*jump,write);
    dft(n/2,poly+jump,2*jump,write+n/2);

	n2 = n/2;
    for(int i=0;i<n2;i++)
        tmp[i] = (v[write+i] + pr[i*jump] * v[write+n2+i]) % mod;
    for(int i=n2;i<n;i++)
        tmp[i] = (v[write+i-n2] + pr[i*jump] * v[write+i]) % mod;
    
    for(int i=0;i<n;i++)
        v[write+i] = tmp[i];

}

void dft_inverse(int n,int poly,int jump,int write){

    if(n == 1){
        v[write] = P[poly];
        return;
    }
    
    dft_inverse(n/2,poly,2*jump,write);
    dft_inverse(n/2,poly+jump,2*jump,write+n/2);
    
    n2 = n/2;
    for(int i=0;i<n2;i++)
        tmp[i] = (v[write+i] + prI[i*jump] * v[write+n2+i]) % mod;
    for(int i=n2;i<n;i++)
        tmp[i] = (v[write+i-n2] + prI[i*jump] * v[write+i]) % mod;
    
    for(int i=0;i<n;i++)
        v[write+i] = tmp[i];
	
}

long long T[maxn];

vector<int> fft(vector<int> a,vector<int> b){

    int n = a.size(), m = b.size();
    
    int N = n + m;
    while(N != (N&-N)) N++;
    
    int u = (mod-1)/N;
    assert((mod-1)%N == 0);
    u = exp(g,u);
    
    long long p = 1;
    for(int i=0;i<N;i++){
        pr[i] = p;
        p = (p*u)%mod;
    }
    
    p = 1;
    int inv = exp(u,mod-2);
    for(int i=0;i<N;i++){
        prI[i] = p;
        p = (p*inv)%mod;
    }

    for(int i=0;i<n;i++)
        P[i] = a[i];
    dft(N,0,1,0);
    for(int i=0;i<N;i++)
        T[i] = v[i];
    for(int i=min(n,m);i<n;i++)
        P[i] = 0;

    for(int i=0;i<m;i++)
        P[i] = b[i];
    dft(N,0,1,0);
    for(int i=0;i<N;i++)
        P[i] = ((long long)T[i] * v[i]) % mod;
        
    dft_inverse(N,0,1,0);

    for(int i=0;i<N;i++)
        P[i] = 0;
    
    vector<int> ret;
    int y = exp(N,mod-2);
    for(int i=0;i<N;i++)
        ret.pb(((long long)v[i]*y)%mod);
        
    return ret;
    
}    

int s[maxn];
int t[maxn];

int a[120];

int A[maxn];
int B[maxn];
int match[maxn];

main(){

		a['A'] = 0;
		a['T'] = 1;
		a['C'] = 2;
		a['G'] = 3;

        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);

        for(int i=0;i<n;i++){
        	char ch;
        	scanf(" %c",&ch);
			s[i] = a[ch];
		}
		for(int i=0;i<m;i++){
			char ch;
			scanf(" %c",&ch);
			t[i] = a[ch];
		}

		for(int l=0;l<4;l++){
		
			A[0] = maxn;
			if(s[0] == l)A[0] = 0;
			for(int i=1;i<n;i++){
				A[i] = A[i-1]+1;
				if(s[i] == l) A[i] = 0;
			}
			if(s[n-1] == l)A[n-1] = 0;
			for(int i=n-2;i>=0;i--)
				A[i] = min(A[i],1+A[i+1]);

			for(int i=0;i<n;i++)
				A[i] = (A[i] <= k) ? 1 : 0;

			for(int i=0;i<m;i++)
				B[i] = (t[i] == l) ? 1 : 0;

			vector<int> va,vb;
			for(int i=0;i<n;i++)
				va.pb(A[i]);
			for(int i=m-1;i>=0;i--)
				vb.pb(B[i]);

			vector<int> p = fft(va,vb);

			for(int i=m-1;i<n;i++)
				match[i] += p[i];

		}

		int ans = 0;
		for(int i=m-1;i<n;i++)
			if(match[i] == m) ans++;

		printf("%d\n",ans);
}