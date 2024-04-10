#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
	int k;
	set<string> einn;
	set<string> nine;
	set<string> ninr;
	set<string> einr;
	set<string> rine;
	set<string> rinn;
	map<string, bool> m;
	map<string, bool> e;
	map<string, bool> n;
	vector<string> a;
	vector<string> b;
	vector<string> ss;
	vector<int> cs;
	cin >> k;
	int tot = 0;
	for(int i=0; i<k; i++){
		string s;
		int c;
		cin >> s >> c;
		ss.push_back(s);
		cs.push_back(c);
		if(c) tot++;
	}
	for(int i=1; i<=k; i++){
		if(i<=tot) {
			e[to_string(i)] = true;
			rine.insert(to_string(i));
		}
		else {
			n[to_string(i)] = true;
			rinn.insert(to_string(i));
		}
	}
	for(int i=0; i<k; i++){
		if(cs[i] == 1){
			if(e[ss[i]]){
				rine.erase(ss[i]);
				m[ss[i]] = true;
			}else if(n[ss[i]]){
				rinn.erase(ss[i]);
				einn.insert(ss[i]);
				m[ss[i]] = true;
			}else{
				einr.insert(ss[i]);
				m[ss[i]] = true;
			}
		}
		else{
			if(e[ss[i]]){
				rine.erase(ss[i]);
				nine.insert(ss[i]);
				m[ss[i]] = true;
			}else if(n[ss[i]]){
				rinn.erase(ss[i]);
				m[ss[i]] = true;
			}else{
				ninr.insert(ss[i]);
				m[ss[i]] = true;
			}
		}
	}
	while(ninr.size()>0 || nine.size()>0 || einr.size() > 0 || einn.size() > 0){
		if(nine.size()>0 && rinn.size() > 0){
			string q = *nine.begin();
			string w = *rinn.begin();
			a.push_back(q);
			b.push_back(w);
			m[q] = false;
			m[w] = true;
			nine.erase(q);
			rinn.erase(w);
			rine.insert(q);
		}
		else if(einn.size()>0 && rine.size() > 0){
			string q = *einn.begin();
			string w = *rine.begin();
			a.push_back(q);
			b.push_back(w);
			m[q] = false;
			m[w] = true;
			einn.erase(q);
			rine.erase(w);
			rinn.insert(q);
		}
		else if(ninr.size()>0 && rinn.size() > 0){
			string q = *ninr.begin();
			string w = *rinn.begin();
			a.push_back(q);
			b.push_back(w);
			m[q] = false;
			m[w] = true;
			ninr.erase(q);
			rinn.erase(w);	
		}
		else if(einr.size()>0 && rine.size() > 0){
			string q = *einr.begin();
			string w = *rine.begin();
			a.push_back(q);
			b.push_back(w);
			m[q] = false;
			m[w] = true;
			einr.erase(q);
			rine.erase(w);
		}else{
			string w = "qweytr";
			string q = *einn.begin();
			a.push_back(q);
			b.push_back(w);
			m[q] = false;
			m[w] = true;
			einn.erase(q);
			einr.insert(w);
			rinn.insert(q);
		}
	}
	cout << a.size() << endl;
	for(int i=0; i<a.size(); i++){
		cout << "move " << a[i] << " " << b[i] << endl;
	}
	return 0;
}