#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
const int maxn=1e6+123,inf=1e9;
int n,k,a,mn=1,last[maxn],mx=inf;
set<int>ms;
vector<int>ans;
bool used[maxn];
int main(){     
	cin>>n>>k;
	stack<int>st;
	for(int i=1;i<=k;i++){
		cin>>a;
		used[a]=1;
		ans.pb(a);
		if(a>mx){
			cout<<-1;
			return 0;
		}
		if(mx==inf)
			mx=a;
		st.push(a);
		while(st.empty()==false && st.top()==mn){
			st.pop();
	  		mn++;
		}
		if(st.empty())
			mx=inf;
	}
	int i=1,cnt=0;
	while(st.empty()==false){
		cnt++;
		if(cnt>1000000){
			cout<<-1;
			return 0;
		}
		//cout<<st.top();
		stack<int>st2;
		for(;i<st.top();i++)
			if(used[i]==false){
				st2.push(i);
			}
		
		while(st2.empty()==false){
			st.push(st2.top());
			ans.pb(st2.top());
			//cout<<st2.top()<<" ";
			st2.pop();

		}

		while(!st.empty() && st.top()==mn){
			st.pop();
	  		used[mn]=1;
			mn++;
		}
	//	cout<<st.top()<<endl;
	}

	for(int i=n;i>0;i--)
		if(!used[i])
			ans.pb(i);
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";

}