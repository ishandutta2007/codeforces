#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;               
int n, a[1010][1010], b[1010][1010], g[1010][1010], h[1010][1010], s[1010][1010], t[1010][1010], x=-1, y;
int main () {                                                     
long k;                          
cin >> n;
s[0][0] = -1;
t[0][0] = -1;
for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		{                     
			scanf("%ld", &k);
			if(k==0) {	
				k=10;
				x=i, y=j;
			}
			while(k%5==0){
				a[i][j]++;
				k/=5;
			}
			while(k%2==0){
				b[i][j]++;
				k/=2;
			}                     			
			if(i){
				if(j){
					h[i][j] = a[i][j];
					g[i][j] = b[i][j];
					if(a[i-1][j]>a[i][j-1] || a[i-1][j]==a[i][j-1] && b[i][j-1]<b[i-1][j]){
						a[i][j]+=a[i][j-1];
						b[i][j]+=b[i][j-1];
						s[i][j] = 0;
					}			
					else {						
						a[i][j]+=a[i-1][j];
						b[i][j]+=b[i-1][j];
						s[i][j]= 1;	
					}

					if(g[i-1][j]>g[i][j-1] || g[i-1][j]==g[i][j-1] && h[i][j-1]<h[i-1][j]){
						g[i][j]+=g[i][j-1];
						h[i][j]+=h[i][j-1]; 
						t[i][j]=0;
					}			
					else {						
						g[i][j]+=g[i-1][j];
						h[i][j]+=h[i-1][j];	
						t[i][j]=1;    

					}

				}
				else {
					a[i][j] += a[i-1][j];
					b[i][j] += b[i-1][j];
					h[i][j] = a[i][j];
					g[i][j] = b[i][j];
					s[i][j] = 1;
					t[i][j] = 1;
				}
			}
			else if(j){
				a[i][j] += a[i][j-1];
				b[i][j] += b[i][j-1];
				h[i][j] = a[i][j];
				g[i][j] = b[i][j];
				s[i][j] = 0;
				t[i][j] = 0;
			}
		}
int z = min(a[n-1][n-1], b[n-1][n-1]), l = min(g[n-1][n-1], h[n-1][n-1]);
string m;
if(x!=-1 && min(z, l)>=1){
	cout << 1 << endl;
	z=0;
	l=0;
	while(z<x) {
		m=m+"D";
	    z++;
	}
    while(l<n-1){
    	m=m+"R";
    	l++;
    }
    while(z<n-1){
    	m = m+"D";
    	z++;
    }
}
else if(z<l){
	cout << z << endl;
	z=n-1, l=n-1;
	while(s[z][l]!=-1){
		if(s[z][l]==0){
			m="R"+m;
			l-=1;
		}
		else {
			m="D"+m;
			z-=1;
		}      
	}
}
else{
cout << l << endl;
	z=n-1, l=n-1;
	while(t[z][l]!=-1){
		if(t[z][l]==0){
			m="R"+m;
			l-=1;
		}
		else{
			m="D"+m;
			z-=1;
		}      
	}
}               
cout << m;
return 0;
}