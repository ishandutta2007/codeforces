#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

typedef pair<int,int> Pii;

void lowest(char* s,vector<int>& remain)
{
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < remain[i]; j++)
			*(s++) = i + 'a';
	}
	*s = '\0';
}

bool up(char* s,const char *t,vector<int>& remain,int size)
{
	if(size == 0){
		*s = '\0';
		return false;	
	} else if(*t == '\0'){
		lowest(s,remain);
		return true;
	} else {
		int use = *t-'a' + 1;
		while(use < 27 && remain[use] == 0) use++;
		if(use == 27) return false;
		remain[use]--;
		*s = (char)(use + 'a');
		lowest(s+1,remain);
		remain[use]++;
		return true;
	}
}

bool eq(char* s,const char *t,vector<int>& remain,int size)
{
	if( size == 0){
		return false;
	} else if(*t == '\0'){
		lowest(s,remain);
		return true;
	} else {
		int use = *t-'a';
		if(remain[use]){
			remain[use]--;
			*s = (char)(use + 'a');
			if(eq(s+1,t+1,remain,size-1)) return true;
			if(up(s+1,t+1,remain,size-1)) return true;
			remain[use]++;
		}
		return up(s,t,remain,size);
	}
}

int main() {

	string a,b;
	cin>>a>>b;
	vector<int> c(27);
	for(int i = 0; i < (int)a.size(); i++){
		c[a[i] - 'a']++;
	}
	char ans[5001];
	bool ok = eq(ans,b.c_str(),c,(int)a.size());
	if(ok)
		cout << ans << endl;
	else
		cout << -1<< endl;


	return 0;
}