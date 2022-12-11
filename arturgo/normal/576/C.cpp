#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int lig, col;
    Point(int _lig = 0, int _col = 0)
    {
        lig = _lig;
        col = _col;
    }
};

vector<int> colonnes[1001];

vector<Point> points;

bool comp(const int &a, const int &b)
{
    if(points[a].lig == points[b].lig)
        return points[a].col < points[b].col;
    return points[a].lig < points[b].lig;
}

int main()
{
    int nbPoints;
    scanf("%d", &nbPoints);
    
    int lig, col;
    for(int iPoint = 0;iPoint < nbPoints;iPoint++)
    {
        scanf("%d%d", &lig, &col);
        points.push_back(Point(lig, col));
        colonnes[col / 1000].push_back(iPoint);
    }
    
    for(int iColonne = 0;iColonne <= 1000;iColonne++)
    {
        sort(colonnes[iColonne].begin(), colonnes[iColonne].end(), comp);
        if((iColonne & 1) == 0)
            for(int iPoint = 0;iPoint < (int)colonnes[iColonne].size();iPoint++)
                printf("%d ", colonnes[iColonne][iPoint] + 1);
        else
            for(int iPoint = (int)colonnes[iColonne].size() - 1;iPoint >= 0;iPoint--)
                printf("%d ", colonnes[iColonne][iPoint] + 1);
    }
    return 0;
}