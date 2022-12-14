var
 n,i:longint;
 s:string;

function get(x:string):string;
begin
 if length(x)=1 then
  if x='9' then exit('198'+x) else exit('199'+x);
 if length(x)=2 then
  if x='99' then exit('19'+x) else exit('20'+x);
 if length(x)=3 then
  if x<'099' then exit('3'+x) else exit('2'+x);
 if length(x)=4 then
  if x<'3099' then exit('1'+x) else exit(x);
 if length(x)=5 then
  if x<'13099' then exit('1'+x) else exit(x);
 if length(x)=6 then
  if x<'113099' then exit('1'+x) else exit(x);
 if length(x)=7 then
  if x<'1113099' then exit('1'+x) else exit(x);
 if length(x)=8 then
  if x<'11113099' then exit('1'+x) else exit(x);
 if length(x)=9 then
  if x<'111113099' then exit('1'+x) else exit(x);
end;

begin
 readln(n);
 for i:=1 to n do
 begin
  readln(s);
  s:=copy(s,5,length(s));
  writeln(get(s));
 end;
end.