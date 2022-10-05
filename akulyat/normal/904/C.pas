Program CodeF_454_C;
var i,j,n,kol,lish,orda:longint;
    //reb:array[1..1]of array[1..2]of longint;
    pot,buk:array[1..26]of integer;
    start:boolean;
    s:string;
    
begin
start:=false;
orda:=ord('a')-1;
readln(n);
kol:=26;
for i:=1 to n do
  begin
  readln(s);
  if s[1]='.' then
    for j:=3 to length(s) do
      begin
      if buk[ord(s[j])-orda]=0 then
        begin
        buk[ord(s[j])-orda]:=-1;
        dec(kol);
        end;
      end;
  for j:=1 to 26 do pot[j]:=0;    
  if s[1]='!' then
    begin
    for j:=3 to length(s) do
      begin
      pot[ord(s[j])-orda]:=1;
      end;
    for j:=1 to 26 do 
      if (pot[j]=0) and (buk[j]=0) then
        begin
        buk[j]:=-1;
        dec(kol);
        end;
    end;  
  if s[1]='?' then
    if buk[ord(s[3])-orda]=0 then
       begin
       buk[ord(s[3])-orda]:=-1;
       dec(kol);
       end;
  if (start=true) and (s[1]<>'.') then
    inc(lish);
  if kol=1 then start:=true;
  //writeln('Teper ', kol, ' ', lish);
  end;
writeln(max(lish-1, 0));





end.