#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>

ll n,a[100010],l,r,x=0,y=0;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	sort(a,a+n);
	l=0,r=n-1;
	while(1){
		if(l<r){
			x+=a[l];
			y+=a[r];
			l++;
			r--;
		}
		else if(l==r){
			y+=a[l];
			break;
		}
		else break;
	}
	cout<<x*x+y*y<<endl;
	return 0;
}