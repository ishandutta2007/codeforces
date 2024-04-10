#include<bits/stdc++.h>
 
#define ll long long 

using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<int> a;
    vector<int> place;
    int read;
    for (int i = 0; i<n; i++) {cin>>read; read--; a.push_back(read);}
    for (int i = 0; i<n; i++) place.push_back(0);
    for (int i = 0; i<n; i++) place[a[i]] = i;
    int counter = 0;
    for (int i = 0; i<n-1; i++)
    {
        if (a[i]!=i)
        {
            int k = place[i];
            swap(a[i], a[k]);
            swap(place[i], place[a[k]]);
            counter++;
        }
    }
    if (counter%2==n%2) cout<<"Petr";
    else cout<<"Um_nik";

    
}