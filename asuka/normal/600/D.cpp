#include<bits/stdc++.h>
#define ll long long
#define N
#define double long double
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const double PI = acos(-1);
double x1,y1,x2,y2,r1,r2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin >> x1 >> y1 >> r1;
 	cin >> x2 >> y2 >> r2;
 	double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
 	if(d >= r1 + r2) return puts("0"),0;
 	if(fabs(r1-r2) >= d) return cout<<fixed << setprecision(20) <<min(r1,r2)*min(r1,r2)*PI,0;
 	// double p = (r1+r2+d)/2;
 	// double S = 2*sqrt(p*(p-d))*sqrt((p-r1)*(p-r2));
 	double ang1 = acos((r1*r1+d*d-r2*r2)/(2*r1*d));
 	double ang2 = acos((r2*r2+d*d-r1*r1)/(2*r2*d));
 	double res = ang1*r1*r1 - 0.5*sin(2*ang1)*r1*r1 + ang2*r2*r2 - 0.5*sin(2*ang2)*r2*r2;
 	cout << fixed << setprecision(20) << res << endl;
	return 0;
}