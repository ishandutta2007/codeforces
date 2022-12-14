const sss:array[1..4]of char=('R','B','Y','G');
var
 s,s1,ss:ansistring;
 fl,i2,i3,i4,r,b,y,g,i,j,k,l,o,m,n,i1,j1,sc,sc1:Longint;
 a,st:array[1..10000]of longint;
begin
 readln(s);
 for i:=1 to length(s) do if s[i]='!' then inc(sc1);
 i:=length(s);
 ss:=s;
 for i1:=1 to 4 do for i2:=1 to 4 do
 for i3:=1 to 4 do for i4:=1 to 4 do
 begin
  fl:=0;
  s:=ss;     for i:=1 to 4 do a[i]:=0;
  if s[1]='!' then begin s[1]:=sss[i1]; inc(a[i1]); end;
  if s[2]='!' then begin s[2]:=sss[i2]; inc(a[i2]); end;
  if s[3]='!' then begin s[3]:=sss[i3]; inc(a[i3]); end;
  if s[4]='!' then begin s[4]:=sss[i4]; inc(a[i4]); end;
  for i:=2 to length(s)-3 do
  begin
   sc1:=0;
   r:=0;b:=0;y:=0;g:=0;
   for j:=i to i+3 do
    if s[j]='R' then inc(r)else
    if s[j]='B' then inc(b)else
    if s[j]='Y' then inc(y)else
    if s[j]='G' then inc(g);
   sc:=0;
    if (r=0)and(s[i+3]='!') then begin inc(a[1]); s[i+3]:=sss[1]; end;
    if (b=0)and(s[i+3]='!') then begin inc(a[2]); s[i+3]:=sss[2]; end;
    if (y=0)and(s[i+3]='!') then begin inc(a[3]); s[i+3]:=sss[3]; end;
    if (g=0)and(s[i+3]='!') then begin inc(a[4]); s[i+3]:=sss[4]; end;
   end;
  for i:=1 to length(s)-3 do
  begin
   r:=0;b:=0;y:=0;g:=0;
   for j:=i to i+3 do
    if s[j]='R' then inc(r)else
    if s[j]='B' then inc(b)else
    if s[j]='Y' then inc(y)else
    if s[j]='G' then inc(g);
    if (r=0)or(g=0)or(b=0)or(y=0)then begin fl:=1; break; end;
  end;
  if fl=1 then continue;
  //writeln(s);
  for i:=1 to 4 do write(a[i],' ');
  halt;
 end;
end.