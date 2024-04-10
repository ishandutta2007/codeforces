program code7;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var n:int;
    s:string;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
begin
  readln(n);
  readln(s)
end;

procedure solve;
 var i:int;
begin
  if (n=2)or(n=3)then begin
    writeln(s);
    halt(0)
  end;
  i:=1;
  if n mod 2<>0 then begin
    write(s[1],s[2],s[3],'-');
    i:=4
  end;

  while i<n-2 do begin
    write(s[i],s[i+1],'-');
    inc(i,2)
  end;
  write(s[i],s[i+1]);
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata;
  solve
end.