#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int a[200000];
map<int,int> ln;
int getlen(int n)
{
    if (n==1) return(1);
    if (ln[n/2]==0) ln[n/2]=getlen(n/2);
	return(2*ln[n/2]+1);
}
int get(int n)
{
    if (n==1) return(1);
	return(2*get(n/2)+n%2);
}
int get(int r, int n)
{
    if (n==0) return(0);
	if (r==0) return(0);
	if (ln[n]==0) ln[n]=getlen(n);
	int len=ln[n];
	if (len<=r) return(get(n));
	if (len/2+1<=r) return(get(n/2)+n%2+get(r-len/2-1,n/2));
	return(get(r,n/2));
}
signed main()
{
    int n;
    cin>>n;
    int l,r;
    cin>>l>>r;
    cout<<get(r,n)-get(l-1,n);
}