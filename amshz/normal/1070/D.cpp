//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define endl "\n"
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=1e6+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));}
ll n ;
ll k ;
ll cnt ;
ll arr[maxn] ;
int main(){
	cin >> n >> k ;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n-1;i++){
		cnt+=arr[i]/k;
		arr[i+1] += arr[i]%k;
		arr[i]%=k;
		if(arr[i]!=0 and arr[i+1] < k){
			cnt++;
			arr[i+1]=0;
		} 
	}
	if(arr[n] % k !=0){
		cnt += arr[n] / k + 1;
	}
	else{
		cnt+=arr[n]/k;
	}
	cout<<cnt<<endl;
	return 0;
}