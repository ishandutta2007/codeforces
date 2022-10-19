#include <iostream>

using namespace std;

#define M 333

int n,a[M],s=0;

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i];
		s+=a[i];
	}
}

void rig(void){
	for (int i=0; i<n; ++i){
		if (a[i]>0){
			--s;
			a[i]--;
			cout<<"P";
		}
		if (i+1<n)
		cout<<"R";
	}
	for (int i=0; i+1<n; ++i)
	cout<<"L";
}

int main()
{
	read();
	while (s>0)
		rig();

	return 0;
}