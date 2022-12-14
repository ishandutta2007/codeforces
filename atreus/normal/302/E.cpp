#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100 + 10 + 10;

string a[maxn];

void desc(string s, string t, string x){
	cout << s << x << t << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	desc("9??", "??0", ">>");
	for (int i = 0; i < 9; i++){
		string fr;
		fr += (char)(i + '0');
		fr += "??";
		string to;
		to += (char)(i + 1 + '0');
		to += "0";
		desc(fr, to, "<>");
	}
	desc("??", "10", "<>");
	for (int i = 0; i <= 9; i++){
		string fr;
		fr += "?";
		fr += (char)(i + '0');
		string to;
		to += (char)(i + '0');
		to += "?";
		desc(fr, to, ">>");
	}
	desc("9?", "??", ">>");
	for (int i = 0; i < 9; i++){
		string fr;
		fr += (char)(i + '0');
		fr += "?";
		string to;
		to += (char)(i + 1 + '0');
		desc(fr, to, "<>");
	}
	desc("", "?", ">>");
}