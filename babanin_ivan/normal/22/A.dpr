program code6;

{$APPTYPE CONSOLE}
{$minstacksize 16000000}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
var a:array[0..1000]of int;
    n:int;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
 var i:int;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
end;

procedure solve;
 var i,j:int;
begin
 for i:=1 to n do
  for j:=1 to n-1 do
   if a[j]>a[j+1]then swap(a[j],a[j+1]);
 i:=1;
 while (a[i]=a[1])and(i<=n) do inc(i);
 if i>n then writeln('NO')
  else begin
        writeln(a[i]);
       end;
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.