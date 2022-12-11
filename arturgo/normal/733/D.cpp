#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bloc {
	int a, b, c, id;
	Bloc(int _a = 0, int _b = 0, int _c = 0, int _id = 0) {
		a = _a;
		b = _b;
		c = _c;
		id = _id;
	}
};

bool operator < (const Bloc &a, const Bloc &b) {
	if(a.a != b.a)
		return a.a < b.a;
	if(a.b != b.b)
		return a.b < b.b;
	return a.c < b.c;
}

vector<Bloc> blocs;

int main() {
	int nbBlocs;
	cin >> nbBlocs;
	
	for(int iBloc = 0;iBloc < nbBlocs;iBloc++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if(a < b)
			blocs.push_back(Bloc(a, b, c, iBloc));
		else
			blocs.push_back(Bloc(b, a, c, iBloc));
		
		if(b < c)
			blocs.push_back(Bloc(b, c, a, iBloc));
		else
			blocs.push_back(Bloc(c, b, a, iBloc));
		
		if(a < c)
			blocs.push_back(Bloc(a, c, b, iBloc));
		else
			blocs.push_back(Bloc(c, a, b, iBloc));
	}
	
	sort(blocs.begin(), blocs.end());
	
	int melSphere = 0;
	vector<int> melBlocs;
	
	for(int iBloc = 0;iBloc < (int)blocs.size();iBloc++) {
		if(iBloc != 0 && blocs[iBloc].a == blocs[iBloc - 1].a && blocs[iBloc].b == blocs[iBloc - 1].b) {
			if(min(blocs[iBloc].a, blocs[iBloc].c + blocs[iBloc - 1].c) >= melSphere) {
				melSphere = min(blocs[iBloc].a, blocs[iBloc].c + blocs[iBloc - 1].c);
				melBlocs.clear();
				melBlocs.push_back(blocs[iBloc].id);
				melBlocs.push_back(blocs[iBloc - 1].id);
			}
		}
		
		if(min(blocs[iBloc].a, blocs[iBloc].c) >= melSphere) {
			melSphere = min(blocs[iBloc].a, blocs[iBloc].c);
			melBlocs.clear();
			melBlocs.push_back(blocs[iBloc].id);
		}
	}
	
	cout << melBlocs.size() << endl;
	
	for(int bloc : melBlocs) {
		cout << bloc + 1 << " ";
	}
	return 0;
}