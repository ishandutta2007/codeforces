program code37B;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var n,heal,reg,maxdmg,m,time,healst:int;
    pow,dmg:array[-1..1100]of int;
    used:array[-1..2000]of bool;
    b:array[-1..2000,-1..3]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

function go:int;
 var f:bool;
     healp,maxsv,maxuse,i:int;
begin
  healp:=heal;
  dec(heal,maxdmg);
  inc(heal,reg);
  heal:=min(heal,healst);
  if heal<=0 then begin
    go:=0;
    exit
  end;

  maxsv:=0;
  maxuse:=0;
  f:=false;
  for i:=1 to n do
    if (not used[i])and(pow[i]>=heal/healst*100)and(dmg[i]>maxsv)then begin
      f:=true;
      maxsv:=dmg[i];
      maxuse:=i;
    end;
  if f then begin
    inc(maxdmg,maxsv);
    used[maxuse]:=true;
    inc(m);  
    b[m,1]:=time;
    b[m,2]:=maxuse;   inc(time);
    go:=go+1         
  end
  else begin
    if healp<=heal then begin
      writeln('NO');
      halt(0);
    end
    else begin
      inc(time);
      go:=go+1;
    end;
  end;
end;

procedure readdata;
 var i,ans:int;
begin
  readln(n,heal,reg);
  maxdmg:=0; healst:=heal;
  m:=0;      time:=0;
  for i:=1 to n do
    readln(pow[i],dmg[i]);
  for i:=1 to n do
    used[i]:=false;
  ans:=go;
  writeln('YES');
  writeln(ans,' ',m);
  for i:=1 to m do
    writeln(b[i,1],' ',b[i,2]);
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata
end.