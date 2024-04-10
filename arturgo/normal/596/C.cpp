#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
};

bool operator < (const Point &a, const Point &b)
{
	if(a.y - a.x == b.y - b.x)
		return a.y < b.y;
	return a.y - a.x < b.y - b.x;
}

vector<Point> ordre;

bool estValide = true;

vector<Point> testeValidite(int debut, int fin)
{
	vector<Point> res;
	if(fin - debut == 1)
	{
		res.push_back(ordre[debut]);
		return res;
	}
	if(fin - debut <= 0)
		return res;
	
	int milieu = (debut + fin) / 2;
	vector<Point> gauche = testeValidite(debut, milieu);
	vector<Point> droit = testeValidite(milieu, fin);
	
	int idGauche = 0, idDroit = 0;
	int minYDroit = 1000 * 1000;
	while(!(idGauche == (int)gauche.size() && idDroit == (int)droit.size()))
	{
		if(idDroit == (int)droit.size())
		{
			if(gauche[idGauche].y >= minYDroit)
				estValide = false;
			res.push_back(gauche[idGauche++]);
		}
		else if(idGauche == (int)gauche.size())
		{
			minYDroit = min(minYDroit, droit[idDroit].y);
			res.push_back(droit[idDroit++]);
		}
		else if(droit[idDroit].x <= gauche[idGauche].x)
		{
			minYDroit = min(minYDroit, droit[idDroit].y);
			res.push_back(droit[idDroit++]);
		}
		else
		{
			if(gauche[idGauche].y >= minYDroit)
				estValide = false;
			res.push_back(gauche[idGauche++]);
		}
	}
	
	return res;
}

int main()
{
	int nbPoints;
	cin >> nbPoints;
	
	set<Point> points;
	
	for(int iPoint = 0;iPoint < nbPoints;iPoint++)
	{
		int x, y;
		cin >> x >> y;
		points.insert(Point(x, y));
	}
	
	for(int iPoint = 0;iPoint < nbPoints;iPoint++)
	{
		int dist;
		cin >> dist;
		set<Point>::iterator it = points.lower_bound(Point(-dist, 0));
		if(it == points.end() || it->y - it->x != dist)
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			ordre.push_back(*it);
			points.erase(it);
		}
	}
	
	testeValidite(0, nbPoints);
	
	if(!estValide)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		for(int iPoint = 0;iPoint < nbPoints;iPoint++)
			cout << ordre[iPoint].x << " " << ordre[iPoint].y << endl;
	}
	return 0;
}