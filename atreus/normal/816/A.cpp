#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

string rev(string a){
	string k;
	for (int i = a.size() - 1; i >= 0; i--)
		k += a[i];
	return k;
}

int init(string a){
	int k = 0;
	for (int i = 0; i < a.size(); i++){
		k *= 10;
		k += a[i] - '0';
	}
	return k;
}

string str(int a){
	string k;
	while (a > 0){
		k += (a % 10) + '0';
		a /= 10;
	}
	return rev(k);
}

int minu(string p, string q){
	int a = init(p), b = init(q);
	return a - b;
}

int main(){
	string s;
	cin >> s;
	string hh = s.substr(0, 2);
	string mm = s.substr(3, 2);
	string pal = rev(hh);
	int k = init(hh);
	k ++;
	string p = str(k);
	p = rev(p);
	if (p.size() == 1)
		p += '0';
	k = init(p);
	if (k >= 60 && (pal < mm || pal >= "60")){	
		int p = k % 10;
		int l = 10 - ((k % 100) / 10);
		k = 60 * l;
		int q = 60 - init(mm);
		cout << p + k + q + 1 << endl;
		return 0;
	}
	if (pal >= mm && pal < "60")
		cout << minu(pal, mm) << endl;
	else {
		if (hh == "23")
			cout << minu("60", mm) << endl;
		else 
			cout << minu("60", mm) + k << endl;
	}
}