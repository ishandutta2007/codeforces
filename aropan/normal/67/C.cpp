#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX 4004

using namespace std;

int main()

{
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);

	char A[MAX],B[MAX];

	int length_A,length_B,INF,wd,wi,ws,wc,H[MAX+2][MAX+2],i,j,DA[MAX+10],d,DB,i1,j1,C,min[4],k,testcase;

	

		scanf("%d%d%d%d\n",&wi,&wd,&wc,&ws);

		scanf("%s\n%s\n",A,B);

		//printf("%s\n\n%s\n",A,B);

		//cin>>wi>>wd>>wc>>ws;

		//cout<<wi<<" "<<wd<<" "<<wc<<" "<<ws<<" ";

		//cin>>A>>B;

		//cout<<A<<" "<<B<<" ";

		length_A = strlen(A);

		length_B = strlen(B);

		//for(int i=0;i<length_B;++i)

			//printf("%c",B[i]);

		//cout<<endl;

		//printf("%s\n",B);

		INF = length_A*wd + length_B*wi + 1;

		H[0][0] = INF;

		//printf("%s\n",B);

		for(i=0;i<=length_A;i++)

		{

			H[i+1][1] = i*wd;

			H[i+1][0] = INF;

		}

		//printf("%s\n",B);

		for(j=0;j<=length_B;j++)

		{

			H[1][j+1] = j*wi;

			H[0][j+1] = INF;

		}

		//printf("%s\n",B);

		for(d=0;d<=MAX;d++)

			DA[d]=0;

		//printf("hahah %s\n",B);

		for(i=1;i<=length_A;i++)

		{

			DB=0;

			//printf("%s\n",B);

			for(j=1;j<=length_B;j++)

			{

				//cout<<A[i-1]<<B[j-1]<<endl;

				i1=DA[(int)(B[j-1])-97];

				j1=DB;

				//if(((int)(A[i-1])-97)==((int)(B[j-1])-97))

					//d=0;

				if ( A[i-1]==B[j-1])

					d=0;

				else

					d=wc;

				//cout<<d<<endl;

				if(d==0)

					DB=j;

				int op=0;

				min[0]=H[i][j]+d;

				min[1]=H[i+1][j]+wi;

				min[2]=H[i][j+1]+wd;

				min[3]=H[i1][j1]+(i-i1-1)*wd+ws+(j-j1-1)*wi;

				H[i+1][j+1]=min[0];

				for(k=1;k<4;k++)

				{

					if(H[i+1][j+1]>min[k]){

						H[i+1][j+1]=min[k];

						op=k;

					}

				}

				/*switch(op){

					case 0:printf("c ");break;

					case 1:printf("i ");break;

					case 2:printf("d ");break;

					case 3:printf("t ");break;

				}*/

				

				

			}

			DA[(A[i-1])-97]=i;

			//printf("\n");

		}

		//printf("%d\n",H[length_A+1][length_B+1]);

		cout<<H[length_A+1][length_B+1]<<endl;

		/*int x=length_A+1,y=length_B+1;

		for( i=0;i<=x;++i){

			for( j=0;j<=y;++j)

				printf("%d ",H[i][j]);

			printf("\n");

		}

		* */

		

		

	//}

}