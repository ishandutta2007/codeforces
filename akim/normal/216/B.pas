var a:array[1..110,1..110]of boolean;
    x:array[1..110]of boolean;
    i,o,n,m,k,l:longint;log:boolean;
procedure dfs(q,p,pr:longint);
var i:longint;
begin
 x[q]:=true;
 for i:=1 to n do
  if a[q,i] then 
   if (not(x[i])) then 
    dfs(i,p+1,q) 
    else 
     if (not(log)) then begin a[q,i]:=false;a[i,q]:=false;if(p mod 2=1)and(i<>pr) then begin inc(o);log:=true;end;end;
end;
begin
 o:=0;
 readln(n,m);
 for i:=1 to m do
 begin
  readln(k,l);
  a[k,l]:=true;
  a[l,k]:=true;
 end;
 for i:=1 to n do
  if not(x[i]) then begin log:=false;dfs(i,1,0);end;
 if (n-o) mod 2=1 then inc(o);
 writeln(o);
end.