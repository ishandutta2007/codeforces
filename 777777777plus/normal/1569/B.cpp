#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		int cnt=0;
		vector<int> q;
		for(int i=0;i<n;++i)
		if(s[i]=='2'){
			q.push_back(i);
		}
		if(q.size()>0&&q.size()<3){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i==j)cout<<"X";
				else if(s[i]=='1'||s[j]=='1')cout<<"=";
				else{
					if(i==q[0]&&j==q[q.size()-1])cout<<"+";
					else if(i==q[q.size()-1]&&j==q[0])cout<<"-";
					else{
						if(i>j)cout<<"+";
						else cout<<"-";
					}
				}
			}
			cout<<endl;
		}
	}
}