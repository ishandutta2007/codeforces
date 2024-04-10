program code4;

{$APPTYPE CONSOLE}


uses
  SysUtils;
type int=integer;
var a:array[1..1000100,1..2]of int64;
    n:int;
    d,m,l:int64;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
 var i,j:int;
begin
 readln(n,d,m,l);
 for i:=1 to n do begin
  a[i,1]:=(i-1)*m;
  a[i,2]:=(i-1)*m+l
 end
end;

procedure solve;
 var j:int;
     i:int64;
begin
 i:=d;
 j:=1;
 while j<=n do
  if (i>=a[j,1])and(i<=a[j,2])then begin
   i:=a[j,2]-(a[j,2] mod d)+d;
   inc(j)
  end
  else
        if (i>a[j,2])then
         while (a[j,2]<i)and(j<=n) do inc(j)
        else if (i>a[j-1,2])and(i<a[j,1])then break;
 writeln(i)
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.