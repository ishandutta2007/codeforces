var a:array['a'..'z','a'..'z']of longint;
    c:char;
    s:string;
    i,n,max:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(s);
  for c:='a' to 'z' do
   if (a[c,s[1]]<>0)and(a[c,s[1]]+length(s)>a[c,s[length(s)]]) then a[c,s[length(s)]]:=a[c,s[1]]+length(s);
  if a[s[1],s[length(s)]]<length(s) then a[s[1],s[length(s)]]:=length(s);
 end;
 max:=0;
 for c:='a' to 'z' do
  if a[c,c]>max then max:=a[c,c];
 writeln(max);
end.