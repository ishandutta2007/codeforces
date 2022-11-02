program Project1;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
const eps=1e-5;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var x,y,i,q:int;
begin
  readln(x,y);
  i:=0;
  while x*x+y*y-i*i>0 do inc(i);
  if (sqr(x)+sqr(y)=sqr(i))or(x=0)or(y=0)then begin
      writeln('black');
      halt(0)
  end;
  q:=1;
  if (x>0)and(y>0)then q:=1;
  if (x<0)and(y>0)then q:=2;
  if (x<0)and(y<0)then q:=3;
  if (x>0)and(y<0)then q:=4;
  if q=1 then begin
    if i mod 2=0 then write('white')
    else write('black');
  end;
  if q=2 then begin
    if i mod 2=1 then write('white')
    else write('black');
  end;
  if q=3 then begin
    if i mod 2=0 then write('white')
    else write('black');
  end;
  if q=4 then begin
    if i mod 2=1 then write('white')
    else write('black');
  end;
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata
end.