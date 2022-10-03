#include <bits/stdc++.h>

using namespace std;

const int MAXN=100 * 1000 + 10;


int n, k, ai;
int A[MAXN];

//deque<int> deq(MAXN);
set<int> st;
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>k;
	for (int i=0; i<k; i++){
		cin>>A[i];
		mp[A[i]]++;
		if (mp[A[i]]==1) st.insert(-A[i]);
		else st.erase(-A[i]);
	}
	if (st.empty()) cout<<"Nothing"<<endl;
	else cout<<-(*st.begin())<<endl;
	
	for (int i=k; i<n; i++){
		cin>>A[i];
		mp[A[i]]++;
		//cerr<<A[i]<<' '<<mp[A[i]]<<endl;
		mp[A[i-k]]--;
		//cerr<<A[i-k]<<' '<<mp[A[i-k]]<<endl;
		
		if (mp[A[i]]==1) st.insert(-A[i]);
		else st.erase(-A[i]);
		
		if (mp[A[i-k]]==1) st.insert(-A[i-k]);
		else st.erase(-A[i-k]);
		
		if (st.empty()) cout<<"Nothing"<<endl;
		else cout<<-(*st.begin())<<endl;
	}
	
	return 0;
}