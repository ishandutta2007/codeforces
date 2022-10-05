Program CodeF_451_C;
var dr,orda,i,j,n:longint;
    //m:array[1..1]of longint;
    nu:array[1..200]of array[1..2000]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    name,how:array[1..2000]of string;
    kol:array[1..2000]of longint;
    s:string;
    
   
    
Function Rs(s:string):string;
var d:string; i:longint;
begin
for i:=length(s) downto 1 do
  d:=d+s[i];
Rs:=d;
end;

Function dodo(kol:longint):string;
var s:string;
begin
s:=' ';
while kol>0 do
  begin
  s:=s+chr(orda+(kol mod 10));
  kol:=kol div 10;
  end;
Rs(s);
dodo:=s;
end;    
    
Function TakeNumbers(s:string; j:longint):string;
var u,i,l,sk:longint;
    pods:array[-1..200]of string;
    itog:string;
begin
l:=length(s);
sk:=-1;
for i:=1 to l do
  begin
  if s[i]=' ' then
    inc(sk) else
  pods[sk]:=pods[sk]+s[i];
  end;
if s[l]=' ' then dec(sk);  

kol[j]:=sk;  
for i:=1 to sk do
  for u:=1 to sk do
    begin
    if (i<>u) and (pods[i]<>'#') then 
      if pos(rs(pods[i]), rs(pods[u]))=1 then
        begin
        pods[i]:='#';
        dec(kol[j])
        end;
      end;
itog:='';    
name[j]:=pods[-1];
for i:=1 to sk do
  begin
  if pods[i]<>'#' then
    itog:=itog+pods[i]+' ';
  end;
TakeNumbers:=itog;  
end;


begin
readln(n);
orda:=ord('0');
for i:=1 to n do
  begin
  readln(s);
  how[i]:=TakeNumbers(s, i);
  end;

//for i:=1 to n do
//    writeln(name[i], ' ', kol[i], ' ', how[i]);


dr:=n;
for i:=1 to n do
  for j:=1 to i-1 do
    begin
    if (name[i]=name[j]) and (i<>j) and (name[i]<>'#') then
      begin
//      writeln('I delete', i);
      name[i]:='#';
      dec(dr);
      how[j]:=how[j]+how[i];
      kol[j]:=kol[j]+kol[i];
      end;
    end;

for i:=1 to n do
  if name[i]<>'#' then
    begin
    s:=name[i]+dodo(kol[i])+' '+how[i];
    //writeln(s);
    how[i]:=takenumbers(s, i);   
    end;
    
    
writeln(dr);
for i:=1 to n do
  if name[i]<>'#' then
    begin
    writeln(name[i], ' ', kol[i],' ',  how[i]);
    end;


{writeln;
writeln('//////');
//writeln(name[1], ' ', name[2]);
writeln(TakeNumbers('ivan 5 23 34 45 56 456', 1))}
end.