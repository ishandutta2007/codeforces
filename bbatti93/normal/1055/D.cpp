#include <bits/stdc++.h>

using namespace std;

long long n, ki;
string s1[3001], s2[3001], s, ss;
vector<int> d, l, r;
long long tl[3001];
bool jo=true;

bool eq(int a) {
    if(l[0]+a<0 || l[0]+a>= s1[d[0]].length()) return false;
    char c1=s1[d[0]][l[0]+a], c2=s2[d[0]][l[0]+a];
    for(int i=1;i<d.size();i++) {
        if(l[i]+a<0 || l[i]+a>= s1[d[i]].length()) return false;
        char c3=s1[d[i]][l[i]+a], c4=s2[d[i]][l[i]+a];
        if(c3!=c1) return false;
        if(c4!=c2) return false;
    }
    return true;
}
int fs(string str, string pattern) {

	// Step 0. Should not be empty string
	if( str.size() == 0 || pattern.size() == 0)
		return -1;

	// Step 1. Compute failure function
	int failure[pattern.size()];
	std::fill( failure, failure+pattern.size(), -1);

	for(int r=1, l=-1; r<pattern.size(); r++) {

		while( l != -1 && pattern[l+1] != pattern[r])
			l = failure[l];

		// assert( l == -1 || pattern[l+1] == pattern[r]);
		if( pattern[l+1] == pattern[r])
			failure[r] = ++l;
	}

	// Step 2. Search pattern
	int tail = -1;
	for(int i=0; i<str.size(); i++) {

		while( tail != -1 && str[i] != pattern[tail+1])
			tail = failure[tail];

		if( str[i] == pattern[tail+1])
			tail++;

		if( tail == pattern.size()-1)
			return i - tail;
	}

	return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s1[i];
        tl[i]=-1;
    }
    for(int i=0;i<n;i++) {
        cin >> s2[i];
    }
    for(int i=0;i<n;i++) {
        bool volt=false;
        for(int j=0;j<s1[i].length();j++) {
            if(s1[i][j]==s2[i][j]) continue;
            if(!volt) {
                volt=true;
                d.push_back(i);
                l.push_back(j);
                r.push_back(j);
                tl[i]=j;
            }
            r.back()=j;
        }
    }
//    for(int i=0;i<d.size();i++) cout << d[i] << " " << l[i] << " " << r[i] << endl;
    long long df=r[0]-l[0]+1;
    for(int i=1;i<d.size();i++) {
        if(r[i]-l[i]+1!=df) jo=false;
    }
    for(int i=0;i<df;i++) {
        if(!eq(i)) jo=false;
    }
    long long ll=0, rr=0;
    while(eq(ll-1)) ll--;
    while(eq(df+rr)) rr++;
    s=s1[d[0]].substr(l[0]+ll, df+rr-ll);
    ss=s2[d[0]].substr(l[0]+ll, df+rr-ll);
//    cout << s << endl;
//    cout << ss << endl;
    for(int i=0;i<n;i++) {
        int x=tl[i]+ll;
        if(tl[i]==-1) x=-1;
        if(fs(s1[i],s)!=x) jo=false;
    }
    if(jo) {
        cout << "YES" << endl;
        cout << s << endl;
        cout << ss << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}