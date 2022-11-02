program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
var a:array[1..200,1..200]of boolean;
    t,n,k,ansx,ansyl,ansyr,i,j,z,q,m,sum1,sum2,y:int;
    f:boolean;
begin
 readln(n,k);
 t:=(k div 2)+1;
 for q:=1 to n do begin
  read(m);
  i:=1;
  j:=1;
  f:=false;
  for i:=1 to k do
   for j:=1 to k do
    if not a[i,j] then begin
     z:=j;
     while (z<=k)and(z-j+1<=m)and(not a[i,z])do inc(z);
     dec(z);
     if z-j+1=m then begin
      if not f then begin
       ansx:=i;
       ansyl:=j;
       ansyr:=z;
       f:=true
      end
      else begin
            sum1:=0;
            sum2:=0;
            for y:=ansyl to ansyr do inc(sum1,abs(ansx-t)+abs(y-t));
            for y:=j to z do inc(sum2,abs(i-t)+abs(y-t));
            if (sum2<sum1)or((sum1=sum2)and(i<ansx))or((sum1=sum2)and(i=ansx)and(j<ansyl))then begin
             ansx:=i;
             ansyl:=j;
             ansyr:=z
            end
           end
     end;
    end;
  if f then begin
   for y:=ansyl to ansyr do a[ansx,y]:=true;
   writeln(ansx,' ',ansyl,' ',ansyr);
  end
  else writeln(-1)
 end
end.