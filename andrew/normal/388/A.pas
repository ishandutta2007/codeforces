var
 a,oe,c:array[0..10000] of longint;
 l,cv,ch,k,mj,m,n,i,j,b,s,v:longint;
begin
 readln(n) ;
 cv:=0;
 for i:=1 to n do
 begin
  read(a[i]);
 end;

 for i:=1 to n-1 do
 begin
 m:=a[i];
  for j:=i to n do if m>a[j] then
                             begin
                              m:=a[j];
                              mj:=j;
                           end;
  a[mj]:=a[i];
  a[i]:=m;
  mj:=0;
 end;
 for i:=1 to n do
 begin
 ch:=0;
 for k:=1 to n do if a[k]>=0 then inc(ch);
 if ch>0 then inc(cv);

 if ch=0 then break ;
  l:=0;
  for j:=1 to n do
  begin
   if (a[j]>=l) and (a[j]>=0) then begin a[j]:=-1; inc(l); end;
  end;
 end;
 writeln(cv);
end.