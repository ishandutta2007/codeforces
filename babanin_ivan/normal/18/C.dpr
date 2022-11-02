program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
var n:int;
    a:array[-1..100100]of int;

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
 for i:=1 to n do read(a[i]);
end;

procedure solve;
 var sumr,suml,i,ans:int;
begin
 sumr:=0;
 for i:=2 to n do
  inc(sumr,a[i]);
 suml:=a[1];
 ans:=0;
 for i:=2 to n do begin
  if suml=sumr then inc(ans);
  inc(suml,a[i]);
  dec(sumr,a[i])
 end;
 writeln(ans)
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.