#include <iostream>
#include <string>

#define M 1000100

using namespace std;

int n,a[10],b[10],g[]={1,2};
string s,t;

void read(void){
	cin>>n;
	n*=2;
	cin>>s>>t;
	for (int i=0; i<n; ++i)
	a[s[i]-'0'+2*(t[i]-'0')]++;
}

void kill(void){
	int t=0;
	for (int i=0; i<n; ++i,t=1-t){
		if (a[3]>0){
			a[3]--,b[t]++;
			continue;
		}
		if (a[g[t]]>0){
			a[g[t]]--,b[t]++;
			continue;
		}
		if (a[g[1-t]]>0){
			a[g[1-t]]--;
			continue;
		}
		a[0]--;
	}
	
	if (b[0]==b[1])
	cout<<"Draw\n";
	if (b[0]>b[1])
	cout<<"First\n";
	if (b[0]<b[1])
	cout<<"Second\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}