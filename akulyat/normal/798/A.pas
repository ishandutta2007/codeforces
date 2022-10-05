Program CodeF_410_A;
var ch:char;
    pol:array[1..15]of byte; 
    num,n,k,i:byte;

begin
k:=0;
n:=0;

while (not eoln) do
  begin
    read(ch);
    num:=ord(ch)-ord('a')+1;
    inc(k);
    pol[k]:=num;  
  end;  

for i:=1 to (k div 2) do
  begin
    if pol[i]=pol[k+1-i] then inc(n);
  end;
if (n=(k div 2)-1) or ((n>=(k div 2)-1) and (k mod 2=1)) then write('YES')
                  else write('NO');
  

end.