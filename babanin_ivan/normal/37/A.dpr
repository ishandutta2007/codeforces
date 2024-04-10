program code37;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var a:array[-1..11000]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var i,n,maxx,ans,x:int;
begin
  for i:=1 to 1000 do
    a[i]:=0;
  readln(n);
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
  end;
  ans:=0;
  maxx:=0;
  for i:=1 to 1000 do
    if a[i]<>0 then begin
      inc(ans);
      maxx:=max(maxx,a[i])
    end;
  write(maxx,' ',ans);
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata;
end.