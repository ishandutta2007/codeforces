program code34A;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var n:int;
    a:array[-1..1000]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var i,minx1,minx2:int;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  minx1:=1;
  minx2:=2;
  for i:=3 to n do
    if (abs(a[i]-a[i-1])<abs(a[minx1]-a[minx2]))then begin
      minx1:=i;
      minx2:=i-1
    end;
  if (abs(a[1]-a[n])<abs(a[minx1]-a[minx2]))then begin
    minx1:=1;
    minx2:=n;
  end;
  writeln(minx1,' ',minx2);
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata
end.