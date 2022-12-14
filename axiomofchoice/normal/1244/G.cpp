#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define int ll

int a[1000010],n,k,sum,delta;
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;
	int sum=n*(n+1)/2;
	repeat(i,1,n+1)a[i]=i;
	if(sum>k)
		cout<<-1<<endl;
	else{
		repeat(i,1,n+1){
			delta=n-2*i+1;
			if(delta<=0)break;
			if(sum+delta<k){
				swap(a[i],a[n-i+1]);
				sum+=delta;
			}
			else{
				swap(a[i],a[i+k-sum]);
				sum=k;
				break;
			}
		}
		cout<<sum<<endl;
		repeat(i,1,n+1)cout<<i<<' ';
		cout<<endl;
		repeat(i,1,n+1)cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}