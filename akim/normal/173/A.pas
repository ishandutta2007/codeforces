{$h+}
var s,t:ansistring;
    ts,tt,ls,lt,n,i,f,g,dch,cch,pp,pn,pp1,pn1:longint;
function nod(x,y:longint):longint;
begin
 if x<>0 then nod:=nod(y mod x,x) else nod:=y;
end;
function nok(x,y:longint):longint;
begin
 nok:=(x div nod(x,y))*y;
end;
begin
 readln(n);
 readln(s);
 readln(t);
 ls:=length(s);
 lt:=length(t);
 g:=nok(ls,lt);
 dch:=n mod g;
 cch:=n div g;
 i:=1;
 while i<=g do
 begin
  ts:=i mod ls;
  if ts=0 then ts:=ls;
  tt:=i mod lt;
  if tt=0 then tt:=lt;
  if s[ts]=t[tt] then else
  if (s[ts]='R')and(t[tt]='S')or(s[ts]='S')and(t[tt]='P')or(s[ts]='P')and(t[tt]='R') then inc(pp) else inc(pn);
  if dch=i then begin pp1:=pp;pn1:=pn;end;
  inc(i);
 end;
 writeln(pn*cch+pn1,' ',pp*cch+pp1);
end.