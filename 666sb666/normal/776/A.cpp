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


			#define GC getchar  (  )

			#define PC putchar



		inline void read   (  int&n  )


		  {  int x=0   , f=1;char ch=GC;while   (   ch<'0'||ch>'9'  )

			{  if   ( ch  ==   '-' )   f=-1;ch=GC; }  while   ( ch   >= '0'&&ch <=  '9'   )   x=  (  x<<1  )  + (  x<<3  )  +ch-'0'  ,  ch=GC;n=x*f;   }

		int outputarray [  20 ]  ;



		inline void write  (  int k )


	  {   int num=0;if   ( k<0 )  PC (  '-'   ) ,  k=-k;do


	{  outputarray  [   ++  num   ]   =k%10 ,  k  /= 10;  } while  ( k   )  ;while (   num ) PC  (  outputarray  [  num -- ]  +'0'  )  ;puts ( ""  )   ;  }



		char a   [   15  ]  ,   b   [   15  ]  ,   c  [   15   ]   ,  d   [ 15  ]  ;


			int main  ( )


			  {


		int n;

	scanf  (  "%s%s"  ,  a  ,  b   )   ;


		read  (  n  )   ;

			printf  (  "%s %s\n" , a ,   b   )   ;


	for   ( int i=1;i   <=   n;i ++ )

		 {



	scanf  (  "%s%s" ,  c ,  d  )   ;


	if   (  !strcmp  ( c , a )  )  memcpy  (  a ,   d  ,  sizeof  ( d   )  )  ;


	else memcpy ( b  , d   ,  sizeof  ( d  )   ) ;

	printf  (  "%s %s\n"  ,   a  , b   )  ;


	  }


			return 0;



	  }