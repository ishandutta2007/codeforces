#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

pair<int, int> a[2][4];

struct Point
{
    int x;
    int y;
};
 
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2;
}

int minx=1e5, miny=1e5, maxy=-1e5, maxx=-1e5;

bool isIntersecting()
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            pair<int, int> p1=a[i][j];
            pair<int, int> p2=a[i][(j+1)%4];

            pair<int, int> normal={p2.y - p1.y, p1.x - p2.x};

            double minA=1e15;
            double maxA=-1e15;

            for(auto p: a[0])
            {
                double projected=normal.x * p.x + normal.y * p.y;

                if(projected<minA)
                    minA=projected;
                if(projected>maxA)
                    maxA=projected;
            }

            double minB=1e15;
            double maxB=-1e15;

            for(auto p: a[1])
            {
                double projected=normal.x * p.x + normal.y * p.y;

                if(projected<minB)
                    minB=projected;
                if(projected>maxB)
                    maxB=projected;
            }

            if (maxA < minB || maxB < minA)
                return false;
        }
    }

    return true;
}


bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {10000, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

int32_t main()
{
    IOS;
    Point polygon[4];
    for(int i=0;i<4;i++)
    {
        cin>>a[0][i].first>>a[0][i].second;
        minx=min(minx, a[0][i].x);
        miny=min(miny, a[0][i].y);
        maxx=max(maxx, a[0][i].x);
        maxy=max(maxy, a[0][i].y);
    }  
    bool check=0;
    for(int i=0;i<4;i++)
    {
        cin>>a[1][i].first>>a[1][i].second;
        int x=a[1][i].x;
        int y=a[1][i].y;
        if(x>=minx && x<=maxx && y>=miny && y<=maxy)
            check=1;
        Point cur;
        cur.x=x;
        cur.y=y;
        polygon[i]=cur;
    } 
    for(int i=0;i<4;i++)
    {
        Point cur;
        cur.x=a[0][i].x;
        cur.y=a[0][i].y;
        if(isInside(polygon, 4, cur))
            check=1;
    }
    if(isIntersecting() || check)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}