#include <iostream>
#include <cstdio>
using namespace std;

struct point
{
    int x, y;
};

point a[2001];

int main()
{
    int ml, mr, n, maxarea, curarea, maxcurl, maxcurr;
    cin >> n;
    maxarea = 0;
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            maxcurl = -1000000000;
            maxcurr = -1000000000;
            int x1 = a[i].x - a[j].x;
            int y1 = a[i].y - a[j].y;
            for (int leftp = 0; leftp < n; leftp++)
            {
                int x2 = a[i].x - a[leftp].x;
                int y2 = a[i].y - a[leftp].y;
                if (x1 * y2 - x2 * y1 > maxcurl)
                    if (i != j && i != leftp && j != leftp)//{
                        maxcurl = x1 * y2 - x2 * y1;
                        //if (i == 0 && j == 2)
                            //cout << leftp << "   maxcurl " << endl;}
            }
            for (int rightp = 0; rightp < n; rightp++)
            {
                int x2 = a[i].x - a[rightp].x;
                int y2 = a[i].y - a[rightp].y;
                if (x2 * y1 - x1 * y2 > maxcurr)
                    if (i != j && i != rightp && j != rightp)//{
                        maxcurr = x2 * y1 - x1 * y2;
                        //if (i == 0 && j == 2)
                            //cout << rightp << "   maxcurr " << endl;}
            }
            if (maxcurr + maxcurl > maxarea){
                maxarea = maxcurr + maxcurl;
                ml = maxcurl; mr = maxcurr;}
                //cout << i << "  ij  " << j << endl;}

        }
    //cout << ml << " " << mr << endl;
    printf("%.9lf", (maxarea) / 2.0);
    return 0;
}