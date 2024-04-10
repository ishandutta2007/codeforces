var
 c1:array[0..100000] of char;
 c:char;
 n,i,k,v,s,j,m,nom:longint;
begin
 readln(n,m);
 s:=0;
 for i:=1 to n do
 begin
  for j:=1 to m do
  begin
   inc(s);
   inc(nom);
   read(c);
   if c='-' then write('-') ;
   if c='.' then
   begin
    if s mod 2=0 then
    begin
     write('B');
     c1[nom]:='B';
    end else
    begin
     write('W');
     c1[nom]:='W';
    end;
   end;
  end;
  if m mod 2=0 then inc(s);
  readln;
  writeln;
  end;
end.