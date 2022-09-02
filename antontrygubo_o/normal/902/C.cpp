#include<iostream>

using namespace std;


int main()
{
int h;
cin>>h;
int a[h+1];
int sum = 0;
for (int i =0; i<=h; i++) {cin>>a[i]; sum += a[i];}
int kek = 0;
while ((kek<h)&&((a[kek]-1)*(a[kek+1]-1)==0)) kek++;
if (kek == h) {cout<<"perfect"; return 0;}
cout<<"ambiguous"<<endl;
int previous[sum];
int current = 0;
previous[0] = 0;
current = 1;
for (int i = 1; i<=h; i++)
{
    for (int j = current; j<current + a[i]; j++ ) previous[j] = current;
    current += a[i];
}
int sum1 = 0;
for (int i = 0; i<=kek; i++) sum1+=a[i];

for (int i = 0; i<sum; i++) cout<<previous[i]<<' ';
cout<<endl;

for (int i = 0; i<sum1; i++) cout<<previous[i]<<' ';
cout<<sum1-1<<' ';
for (int i = sum1+1; i<sum; i++) cout<<previous[i]<<' ';

}