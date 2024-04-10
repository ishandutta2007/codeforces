	#include<cstdio>

		#include<cstring>

		#include<cmath>

	#include<cstdlib>


	#include<iostream>


	#include<algorithm>



	#include<string>

			#include<vector>

			#include<queue>

			#include<set>



	#include<map>



	using namespace std;


		#define GC getchar   (   )


	#define PC putchar

			inline void read (  int&n   )



			  {  int x=0  ,  f=1;char ch=GC;while (  ch<'0'||ch>'9'  )

			{   if   (  ch   == '-'  ) f=-1;ch=GC;   }  while   (  ch   >=  '0'&&ch  <=  '9'  )   x=  ( x<<1  )  +   ( x<<3  ) +ch-'0'  , ch=GC;n=x*f;  }

		int outputarray [ 20 ] ;



		inline void write  (  int k   )


		  {  int num=0;if  (  k<0 )  PC   ( '-'   )  , k=-k;do

			{  outputarray [  ++   num ]  =k%10 ,  k  /= 10;   } while   (   k   ) ;while ( num  ) PC ( outputarray [  num  --  ] +'0'  )  ;puts (   ""  )  ; }


			int k ,  q;

		double f [ 10005  ]  [  1005 ]  ;

			int main  (  )

			  {


		read  ( k ) ;read ( q ) ;


	f   [ 0   ]   [   0  ]  =1;


			for   (   int i=1;i <=  10000;i  ++   )

	for (  int j=1;j <=   1000;j   ++  ) f [  i ]  [   j   ] =f  [ i-1 ]  [   j   ] *  (   (  double )  j/k   )  +f  [   i-1   ] [ j-1  ]   * ( 1.0-   (   ( double  ) (   j-1   )   ) /k ) ;

			while  (  q   --   )

	   {

	int p;

		read  (   p  ) ;



		int ans;


	for   ( ans=1;ans <= 10000;ans   ++ )  if  (  f [  ans ]  [  k ]  *2000>p  )   break;

		write (   ans  )   ;



		 }


			return 0;


	  }