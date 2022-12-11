#include <iostream>
using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string deb = "What are you doing while sending \"";
string mil = "\"? Are you busy? Will you send \"";
string fin = "\"?";

long long sz(long long n) {
	if(n == 0)
		return f0.size();
	return (long long)deb.size() + mil.size() + fin.size() + 2 * sz(n - 1);
}

char findChar(long long n, long long k) {
	if(n == 0) {
		if(k >= (int)f0.size()) {
			return '.';
		}
		return f0[k];
	}
	long long dec = 0;
	long long taille = deb.size();
	if(k < dec + taille) {
		return deb[k - dec];
	}
	dec += taille;
	if(n < 54)
		taille = sz(n - 1);
	if(n >= 54 || k < dec + taille) {
		return findChar(n - 1, k - dec);
	}
	dec += taille;
	taille = mil.size();
	if(k < dec + taille) {
		return mil[k - dec];
	}
	dec += taille;
	taille = sz(n - 1);
	if(k < dec + taille) {
		return findChar(n - 1, k - dec);
	}
	dec += taille;
	taille = fin.size();
	if(k < dec + taille) {
		return fin[k - dec];
	}
	return '.';
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbReqs;
	cin >> nbReqs;
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		long long n, k;
		cin >> n >> k;
		cout << findChar(n, k - 1);
	}
	cout << endl;
	return 0;
}