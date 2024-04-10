#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<pair<int, int> > t;
int nb, p;

int nbEntre(int a) {
	return t[a].second - t[a].first + 1;
}

int nbEntreP(int a) {
	return t[a].second / p - (t[a].first - 1) / p;
}

int main() {
	cin >> nb >> p;
	
	for(int i = 0;i < nb;i++) {
		int deb, fin;
		cin >> deb >> fin;
		t.push_back(make_pair(deb, fin));
	}
	
	double res = 0;
	for(int i = 0;i < nb;i++) {
		res += 1 - ((nbEntre(i) - nbEntreP(i)) / (double)(nbEntre(i))) * ((nbEntre((i + 1)%nb) - nbEntreP((i + 1)%nb)) / (double)(nbEntre((i + 1)%nb)));
	}
	
	cout << fixed << setprecision(8);
	cout << res * 2000 << endl;
	return 0;
}