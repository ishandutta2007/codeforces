program code5;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var a:array[-1..1000]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var n,ans1,ans2,i:int;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans1:=0;
  ans2:=0;
  for i:=1 to n do
    if a[i] mod 2=0 then inc(ans1)
    else inc(ans2);
  if ans1=1 then begin
    for i:=1 to n do
      if a[i] mod 2=0 then writeln(i)
  end
  else begin
    for i:=1 to n do
      if a[i] mod 2<>0 then writeln(i)
  end
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata
end.