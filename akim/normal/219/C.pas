var n,m,o1,o2,i,l:longint;
    s,t:ansistring;
begin
 readln(n,m);
 readln(s);
 l:=length(s);
 if m=2 then
 begin
  t:=s;
  for i:=1 to l do
   if i mod 2=1 then
   begin if s[i]='A' then inc(o1) else inc(o2);end else
   begin if s[i]='B' then inc(o1) else inc(o2);end;
  if o1>o2 then
  begin
   writeln(l-o1);
   for i:=1 to l do
    if i mod 2=1 then write('A') else write('B');
  end else
  begin
   writeln(l-o2);
   for i:=1 to l do
    if i mod 2=1 then write('B') else write('A');
  end;
 end else
 begin
  s:=s+'!';
  for i:=1 to l-1 do
   if (s[i]=s[i+1])then
   if (s[i]<>'A')and(s[i+2]<>'A') then begin s[i+1]:='A';inc(o1);end else
   if (s[i]<>'B')and(s[i+2]<>'B') then begin s[i+1]:='B';inc(o1);end else
   if (s[i]<>'C')and(s[i+2]<>'C') then begin s[i+1]:='C';inc(o1);end;
  writeln(o1);
  delete(s,l+1,1);
  writeln(s);
 end;
end.