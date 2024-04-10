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
int gen[100];
/*map<int,int> gen[100];
int get(int u, int mask)
{
    if (gen[u][mask]!=0) return(gen[u][mask]);
	if (u==0) return(0);
	int a[200];
	for (int i=0;i<=19;i++)
		a[i]=0;
	for (int i=1;i<=u;i++)
	{

		if ((mask&(1<<(i-1)))==0)
			a[get(u-i,mask+(1<<(i-1)))]=1;
        //cout<<i<<' '<<u<<' '<<gen[u-i][mask+(i<<(i-1))]<<'\n';
	}
	int now=0;
	while (a[now]) now++;
	gen[u][mask]=now;
	return(now);
}*/
signed main()
{
    gen[1]= 1;
    gen[2]= 1;
    gen[3]= 2;
    gen[4]= 2;
    gen[5]= 2;
    gen[6]= 3;
    gen[7]= 3;
    gen[8]= 3;
    gen[9]= 3;
    gen[10]= 4;
    gen[11]= 4;
    gen[12]= 4;
    gen[13]= 4;
    gen[14]= 4;
    gen[15]= 5;
    gen[16]= 5;
    gen[17]= 5;
    gen[18]= 5;
    gen[19]= 5;
    gen[20]= 5;
    gen[21]= 6;
    gen[22]= 6;
    gen[23]= 6;
    gen[24]= 6;
    gen[25]= 6;
    gen[26]= 6;
    gen[27]= 6;
    gen[28]= 7;
    gen[29]= 7;
    gen[30]= 7;
    gen[31]= 7;
    gen[32]= 7;
    gen[33]= 7;
    gen[34]= 7;
    gen[35]= 7;
    gen[36]= 8;
    gen[37]= 8;
    gen[38]= 8;
    gen[39]= 8;
    gen[40]= 8;
    gen[41]= 8;
    gen[42]= 8;
    gen[43]= 8;
    gen[44]= 8;
    gen[45]= 9;
    gen[46]= 9;
    gen[47]= 9;
    gen[48]= 9;
    gen[49]= 9;
    gen[50]= 9;
    gen[51]= 9;
    gen[52]= 9;
    gen[53]= 9;
    gen[54]= 9;
    gen[55]= 10;
    gen[56]= 10;
    gen[57]= 10;
    gen[58]= 10;
    gen[59]= 10;
    gen[60]= 10;
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        ans^=gen[a];
    }
    if (ans==0) cout<<"YES"; else cout<<"NO";
}