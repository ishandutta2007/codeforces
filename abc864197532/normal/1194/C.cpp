#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;

int main () {
	int t;
	cin >> t;
	for (int a=0;a<t;++a) {
		string s,t,x;
		cin >> s >> t >> x;
		int n_s=0,n_t=0,l_t=t.length(),l_s=s.length(),i;
		while (n_t<l_t and n_s<l_s) {
			if (t[n_t]==s[n_s]) n_s++;
			n_t++;
		}
		if (n_s!=l_s) {
			cout << "NO" << endl;
		} else {
			int aa[26],bb[26],cc[26];
			for (i=0;i<26;++i) {
				aa[i]=0;
				bb[i]=0;
				cc[i]=0;
			} for (i=0;i<s.length();++i) aa[s[i]-'a']++; 
			for (i=0;i<t.length();++i) bb[t[i]-'a']++; 
			for (i=0;i<x.length();++i) cc[x[i]-'a']++;
			bool is=true; 
			for (i=0;i<26;++i) {
				if (aa[i]+cc[i]<bb[i]) is=false;
			}
			if (is) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}