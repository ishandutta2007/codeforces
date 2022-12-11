#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <cmath>
using namespace std;

struct Droite
{
	long long a, b;
	int id;
	Droite(long long _a = 0, long long _b = 0, int _id = 0)
	{
		a = _a;
		b = _b;
		id = _id;
	}
};

int nbDroites;
long long x1, x2;

vector<Droite> avant, apres;

bool compAvant(const Droite &a, const Droite &b)
{
	long long imageA = a.a * x1 + a.b;
	long long imageB = b.a * x1 + b.b;
	if(imageA == imageB)
		return a.a < b.a;
	return imageA < imageB;
}

bool compApres(const Droite &a, const Droite &b)
{
	long long imageA = a.a * x2 + a.b;
	long long imageB = b.a * x2 + b.b;
	if(imageA == imageB)
		return a.a > b.a;
	return imageA < imageB;
}

int main()
{
	cin >> nbDroites;
	cin >> x1 >> x2;
	
	for(int iDroite = 0;iDroite < nbDroites;iDroite++)
	{
		long long a, b;
		cin >> a >> b;
		Droite cur = Droite(a, b, iDroite);
		avant.push_back(cur);
		apres.push_back(cur);
	}
	
	sort(avant.begin(), avant.end(), compAvant);
	sort(apres.begin(), apres.end(), compApres);
	
	for(int iDroite = 0;iDroite < nbDroites;iDroite++)
		if(avant[iDroite].id != apres[iDroite].id)
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}