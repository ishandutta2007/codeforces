#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

#define u64 long long

using namespace std;


int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");    
    int n,m;
    
    vector<int> card1;
    
    in>>n;
    
    for(int i=0;i<n;i++)
    {
            int tmp;
            in>>tmp;
            card1.push_back(tmp);
    }
    
    in>>m;
    
    for(int i=0;i<m;i++)
    {
            int tmp;
            in>>tmp;
            card1.push_back(tmp);
    }
    
    int x=0,y=0;
    bool search=0;
    vector<int> sectors;
    bool f=false;
    vector<int> cards;
    while(x<n || y<m)
    {
              if(x<n && y<m)
              {
                     int xi=0,yi=0;
                     for(int i=n-x-1;i>=0;i--)
                     {
                             if(card1[i]==search)
                             xi++;
                             else
                             break;
                             cards.push_back(i+1);
                     }
                     for(int i=n+m-y-1;i>=n;i--)
                     {
                             if(card1[i]==search)
                             yi++;
                             else
                             break;
                             cards.push_back(i+1);
                     }
                     sectors.push_back(xi+yi);
                     x+=xi;
                     y+=yi;
                     search=!search;
              }
              else if(x<n)
              {
                   int xi=0;
                   for(int i=n-x-1;i>=0;i--)
                     {
                             if(card1[i]==search)
                             xi++;
                             else
                             break;
                             cards.push_back(i+1);
                     }
                     sectors.push_back(xi);
                     x+=xi;
                     search=!search;
              }
              else
              {
                  int yi=0;
                  for(int i=n+m-y-1;i>=n;i--)
                     {
                             if(card1[i]==search)
                             yi++;
                             else
                             break;
                             cards.push_back(i+1);
                     }
                     sectors.push_back(yi);
                     y+=yi;
                     search=!search;
              }
    }
    out<<cards[n+m-1];
    for(int i=n+m-2;i>=0;i--)
    out<<' '<<cards[i];
    
    out<<endl;
    out<<sectors.size()-1<<endl;
    int anser=sectors[sectors.size()-1];
    out<<sectors[sectors.size()-1];
    for(int i=sectors.size()-2;i>0;i--)
    {
            anser+=sectors[i];
            out<<' '<<anser;
    }
    out<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}