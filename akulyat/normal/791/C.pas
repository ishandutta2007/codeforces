Program CodF_405VK_C;
var  pos,sl:array[1..50]of byte;
     rea:array[1..50]of string;
     orda,ords,i,n,k,q:byte;
     sim:char;


begin
readln(n,k);
for i:=1 to n-k+1 do
   begin
      while (not eoln) do
         begin
            read(sim);
            if sim='N' then
               begin
                  inc(q);
                  pos[q]:=0;
               end;
            if sim='Y' then
               begin
                  inc(q);
                  pos[q]:=1;
               end;  
         end;
   end;

for i:=1 to n do
   sl[i]:=i;
for i:=1 to n-k+1 do
  if pos[i]=0 then
     sl[k+i-1]:=sl[i];
orda:=ord('A')-1;
ords:=ord('a')-1;

for i:=1 to n do
   if sl[i]<=26 then
      rea[i]:='D'+chr(ords+sl[i])
                else
      rea[i]:='Q'+chr(ords+sl[i]-26);          
for i:=1 to n do write(rea[i], ' ');
end.